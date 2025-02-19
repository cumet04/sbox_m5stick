## 開発環境メモ
* コード書き環境はWSL側のvscodeにarduino拡張 (vscode-arduino.vscode-arduino-community) を入れる
* 拡張にビルトインなCLIを使うため、CLIを使う的な設定を有効にする必要がある
* vscode拡張側で、M5StickCPlusのライブラリインストールをする（ライブラリマネージャ）
* デバイスへのアップロードはWSL/vscode側からは触らない。windows側にCLIを入れ、それをupload.shから呼び出す
  - win側の実行ファイルを適当にPATHにsymlink想定

