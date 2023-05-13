# sudo
## インストール
apt install sudo

## 設定
1. 「update-alternatives --config editor」を実行し、「vim」を選択する。
1. 「visudo」を実行し、下記を記載する。

* 認証の試行は、３回まで
```
Defaults passwd_tries=3
```

* パスワードが不正だった場合は、カスタムメッセージを表示する
```
Defaults badpass_message="badpass"
```

* sudoコマンドの履歴（入出力）を、「/var/log/sudo」ディレクトリに残す
```
Defaults log_input, log_output, iolog_dir="/var/log/sudo"
```

* TTYモードを有効にする
```
Defaults requiretty
```

* sudo時のパスを制限する
```
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```
