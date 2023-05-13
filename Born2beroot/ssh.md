# SSH
## 設定
* ポートを「4242」に変更
```
/etc/ssh/sshd_config
	Port 4242
```

* rootでのログイン不可
```
/etc/ssh/sshd_config
	PermitRootLogin no
```
