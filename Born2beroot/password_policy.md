# パスワードポリシー
## インストール
sudo apt install libpam-pwquality

## 設定
パスワードポリシーを適用するため、すべてのアカウント（root含む）のパスワードを変更する必要があります。

* パスワードを変更しなくてよい最長日数は、30日
```
/etc/login.defs
	PASS_MAX_DAYS 30
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
/etc/pam.d/common-password
	minlen 10
```

* パスワードは、大文字、小文字、数字を含む
```
/etc/pam.d/common-password
	ucredit -1
	lcredit -1
	dcredit -1
```

* 連続する同一文字を3文字以上含めない
```
/etc/pam.d/common-password
	maxrepeat 3
```

* パスワードにユーザー名を含めない
```
/etc/pam.d/common-password
	usercheck 1
```

* 旧パスワードから7文字以上変更しなければならない  
（注）rootユーザは除外
```
/etc/pam.d/common-password
	difok 7
```

* rootユーザにもパスワードポリシーを適用する
```
/etc/pam.d/common-password
	enforce_for_root
```

## 既存ユーザへのパスワードポリシーの適用
sudo chage -M 30 -m 2 -W 7 _user_  
sudo passwd _user_  

## パスワードポリシーのテスト
chage -l _user_  
