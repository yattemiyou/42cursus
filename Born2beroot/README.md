# Born2beRoot
## 確認事項
1. 暗号化されたパーティションを２つ以上作成  
   1. 「lsblk」を実行し、確認する。

1. sshdのポート番号が「4242」に変更されていることを確認する。  
   1. 「ss -lt」を実行し、ポート番号「4242」でリッスンしていることを確認する。
   1. 「ssh b2b@192.168.1.42」を実行し、接続できないことを確認する。
   1. 「ssh -p 4242 b2b@192.168.1.42」を実行し、接続できることを確認する。
   1. 「ssh -p 4242 root@192.168.1.42」を実行し、接続できないことを確認する。

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

1. ポート番号の変更  
   （参考）
   https://marusankakusikaku.jp/linux/debian-ssh/
   1. 設定ファイルを編集する。  
      「vi /etc/ssh/sshd_config」を実行し、下記を編集する。  
      ```
      #Port 22
	  ↓
      Port 4242
      ```
   1. 再起動する。  
      「reboot」を実行し、ポート番号が変更されていることを確認する。  
