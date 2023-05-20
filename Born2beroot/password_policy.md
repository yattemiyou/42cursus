# パスワードポリシー
## インストール
sudo apt install libpam-pwquality
sudo apt install libpwquality-tools

## 設定
パスワードポリシーを適用するため、すべてのアカウント（root含む）のパスワードを変更する必要があります。

* パスワードは30日ごとに期限切れ
```
/etc/login.defs
	PASS_MAX_DAYS 29?
```

* パスワードが変更できるまでの最短日数は、2日
```
/etc/login.defs
	PASS_MIN_DAYS 2
```

* パスワード期限が切れる前に警告される日数は、7日
```
/etc/login.defs
	PASS_WARN_AGE 7
```

* パスワードの長さは、10文字以上
```
/etc/security/pwquality.conf
	minlen 10
```

* パスワードは、大文字、小文字、数字を含む
```
/etc/security/pwquality.conf
	ucredit -1
	lcredit -1
	dcredit -1
```

* 連続する同一文字を3文字より多く~~以上~~含めない
```
/etc/security/pwquality.conf
	maxrepeat 3
```

* パスワードにユーザー名を含めない
```
/etc/security/pwquality.conf
	usercheck 1
```

* 旧パスワードから7文字以上変更しなければならない  
（注）rootユーザは除外
```
/etc/security/pwquality.conf
	difok 7
```

* rootユーザにもパスワードポリシーを適用する
```
/etc/security/pwquality.conf
	enforce_for_root
```

## 既存ユーザへのパスワードポリシーの適用
sudo chage -M 30 -m 2 -W 7 _user_  
sudo passwd _user_  

## パスワードポリシーのテスト
chage -l _user_  
