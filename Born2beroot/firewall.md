# ファイアウォール
## インストール
```
apt install ufw
systemctl enable ufw.service
systemctl start ufw.service
ufw enable
```

## 設定
* 受信パケットのデフォルトルール（拒否）
```
ufw default deny incoming
```

* 送信パケットのデフォルトルール（許可）
```
ufw default allow outgoing
```

* SSHを許可
```
ufw allow 4242/tcp
ufw reload
```
