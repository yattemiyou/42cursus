# Born2beRoot
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
   1. 「sudo sudo -V」を実行し、下記を確認する。  
      * 認証の試行回数  

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

1. sudo  
   （参考）  
   https://linuxjm.osdn.jp/html/sudo/man5/sudoers.5.html  
   https://ja.linux-console.net/?p=2263#gsc.tab=0  
   1. インストール  
      1. 「apt install sudo」を実行する。  
   1. エディタの変更  
      1. 「update-alternatives --config editor」を実行し、「vim」を選択する。  
   1. 認証の試行回数  
      1. 「visudo」を実行し、下記を追記する。  
      ```
      Defaults passwd_tries=3
      ```
   1. 認証失敗時のメッセージ  
      1. 「visudo」を実行し、下記を追記する。  
      ```
      Defaults badpass_message="badpass"
      ```
   1. ロギング  
      1. 「visudo」を実行し、下記を追記する。  
      ```
      Defaults log_input, log_output, iolog_dir="/var/log/sudo"
      ```
   1. TTYモードの有効化  
      1. 「visudo」を実行し、下記を追記する。  
      ```
      Defaults requiretty
      ```
   1. sudoから実行するコマンドのパス  
      1. 「visudo」を実行し、下記を追記する。  
      ```
	  Defaults secure_path=".../bin:/snap/bin"
      ```

1. ユーザー設定  
   1. グループの作成  
      1. 「groupadd user42」を実行する。  
   1. 「user42」グループへの登録  
      1. 「gpasswd -a b2b user42」を実行する。  
   1. 「sudo」グループへの登録  
      1. 「gpasswd -a b2b sudo」を実行する。  
