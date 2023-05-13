# 監視スクリプト
## 設定
1. 「monitoring.sh」を「/root」に配置する。
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
```
