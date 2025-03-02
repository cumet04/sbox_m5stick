## 開発環境メモ
* WSL側のvscodeにarduino拡張を入れる (`.vscode/extensions.json`に従う)
* vscode拡張側で、M5StickCPlusのライブラリインストールをする（ライブラリマネージャ）
* デバイスへのアップロードはWSL/vscode側からは触らない。windows側にCLIを入れ、それをupload.shから呼び出す
  - win側の実行ファイルを適当にPATHにsymlink想定

