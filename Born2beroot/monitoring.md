# 監視スクリプト
## 設定
1. 「monitoring.sh」を「/root」に配置する。
1. 「crontab -e」を実行し、下記を追記する。
```
*/10 * * * * /root/monitoring.sh
```
