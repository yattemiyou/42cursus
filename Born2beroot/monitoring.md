# 監視スクリプト
## 設定
1. 「monitoring.sh」を「/root」に配置する。
1. 「chmod +x monitoring.sh」で実行権限を付与する。
1. 「sudo date」を実行し、sudoの履歴を残す。
1. 手動で「monitoring.sh」を実行し、動作確認する。
1. 「crontab -e」を実行し、下記を追記する。
```
*/10 * * * * /root/monitoring.sh
```

## 中断
### サーバ全体
```
systemctl stop cron.service
```

### rootユーザのみ
```
cd /var/spool/cron/crontabs
mv root root_
```

### 監視スクリプトのみ
```
cd /root
mv monitoring.sh monitoring.sh_
or
chmod -x monitoring.sh
```

## 再開
### サーバ全体
```
systemctl start cron.service
```

### rootユーザのみ
```
cd /var/spool/cron/crontabs
mv root_ root
```

### 監視スクリプトのみ
```
cd /root
mv monitoring.sh_ monitoring.sh
or
chmod +x monitoring.sh
```
