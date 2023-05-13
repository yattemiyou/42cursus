# Born2beroot

## 提出物
仮想ディスクのハッシュ（sha1）を記載した「signature.txt」ファイルのみ

## 必須課題
### OS
* 最小構成とする
* GUIは、不可
* Debian or Rockyの最新安定バージョン
* LVM上に最低でも２つ以上のパーティション
* ホスト名は、ユーザ名＋42(例:wil42）
* 強力なパスワードポリシー
* 厳格なルールに従いsudoのインストールと設定
* rootユーザに加え、ログインユーザー名と同一名のユーザ
* 上記のユーザは、「user42」、「sudo」グループに所属

### SSH
* ポートは、4242
* rootでのログイン不可

### ファイアウォール
* 仮想マシンの起動時からアクティブ
* 4242のみを開放

### 監視スクリプト（monitoring.sh）
* bashで実装
* サーバ起動後、１０分ごとに、すべてのターミナルに以下の項目を表示（wallコマンドを使用）する
* バナーは任意だが、エラーの内容は、表示しないようにする  
（表示項目）
* The architecture of your operating system and its kernel version.
* The number of physical processors.
* The number of virtual processors.
* The current available RAM on your server and its utilization rate as a percentage.
* The current available memory on your server and its utilization rate as a percentage.
* The current utilization rate of your processors as a percentage.
* The date and time of the last reboot.
* Whether LVM is active or not.
* The number of active connections.
* The number of users using the server.
* The IPv4 address of your server and its MAC (Media Access Control) address.
* The number of commands executed with the sudo program.

### その他
以下は、課題の要件の一部を確認するために使用できる２つのコマンドです。
* /usr/sbin/aa-status 
* ss -tunlp

## 確認事項
1. 暗号化されたパーティションを２つ以上作成  
   1. 「lsblk」を実行し、確認する。

1. sshdのポート番号が「4242」に変更されていることを確認する。  
   1. 「ss -lt」を実行し、ポート番号「4242」でリッスンしていることを確認する。
   1. 「ssh b2b@192.168.1.42」を実行し、接続できないことを確認する。
   1. 「ssh -p 4242 b2b@192.168.1.42」を実行し、接続できることを確認する。
   1. 「ssh -p 4242 root@192.168.1.42」を実行し、接続できないことを確認する。

1. ファイアウォールが自動で起動していることを確認する。  
   1. 「systemctl status ufw.service」を実行し、確認する。  
   1. 「ufw status」を実行し、確認する。  

1. ユーザ  
   1. 「id -Gn b2b」を実行し、「sudo」、「user42」グループに所属していることを確認する。  

1. sudo  
   1. 「sudo sudo -V」を実行し、下記の設定を確認する。  
      * 認証の試行回数  
	    ⇒パスワード入力の試行回数: 3  
      * メッセージ  
	    ⇒パスワードを間違った時のメッセージ: 42 Tokyo  
      * ロギング  
        * コマンドを実行した時のユーザー入力をログに記録します
        * コマンドを実行した時の出力をログに記録します
        * 入出力 (I/O) ログを保存するディレクトリです:/var/log/sudo

   1. ロギングを確認する。  
      1. 「sudo id」コマンドを実行する。
      1. 「sudo cat /var/log/sudo/seq」コマンドを実行し、シーケンス番号を確認する。  
      1. 「sudo sudoreplay -d /var/log/sudo シーケンス番号」を実行し、入出力が記録されていることを確認する。  


## 環境構築
1. ネットワークアダプタの追加  
   （参考）
   https://www.kwonline.org/memo2/2020/01/21/debian-10%E3%81%A7nic%E3%82%922%E6%9E%9A%E5%90%8C%E6%99%82%E3%81%AB%E6%9C%89%E5%8A%B9%E3%81%AB%E3%81%99%E3%82%8B/
   1. 「内部ネットワーク」を追加する。  
      ホスト／ゲスト間の場合は、「ホストオンリーアダプター」
   1. 設定ファイルを編集する。  
      「vi /etc/network/interfaces」を実行し、下記を追記する。  
      ```
      allow-hotplug enp0s8
      iface enp0s8 inet static
      address 192.168.1.42
      netmask 255.255.255.0
      ```
   1. 再起動する。  
      「reboot」を実行し、pingできることを確認する。  

1. 文字化けへの対応  
   （参考）
   https://izumii19.hatenablog.com/entry/2018/11/15/225313
   1. 設定ファイルを編集する。  
      「vi /etc/bash.bashrc」を実行し、下記を追記する。  
      ```
      case $TERM in
          linux) LANG=C ;;
          *) LANG=ja_JP.UTF-8 ;;
      esac
      ```
   1. 再起動する。  
      「reboot」を実行し、文字化けが解消されていることを確認する。  
