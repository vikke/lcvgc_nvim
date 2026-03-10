;; 予約語
["device" "instrument" "kit" "clip" "scene" "session"
 "include" "use" "resolution" "tempo" "time"
 "port" "channel" "note" "bars" "arp" "scale"
 "gate_normal" "gate_staccato"] @keyword

;; play / stop は専用グループ（太字で目立たせる）
["play"] @keyword.play
["stop"] @keyword.stop

;; loop / repeat
["loop" "repeat"] @keyword.repeat

;; ユーザー定義名（定義側）
(device_def (identifier) @type.definition)
(instrument_def (identifier) @type.definition)
(kit_def (identifier) @type.definition)
(clip_def (identifier) @function.definition)
(scene_def (identifier) @function.definition)
(session_def (identifier) @function.definition)

;; ユーザー定義名（参照側）
(scene_slot (identifier) @function)
(play_stmt (identifier) @function)
(session_entry (identifier) @function)
(use_stmt (identifier) @type)

;; 音名
(note_name) @constant

;; コード名
(chord_name) @string.special

;; 数値（オクターブ、音長、テンポ等）
(octave) @number
(duration) @number
(number) @number

;; ステップシーケンサーパターン (x.oX|)
(step_pattern) @string

;; scene内の確率
(scene_slot (probability) @number.special)

;; scene内のシャッフル |
(shuffle_expr "|" @operator)

;; 重み (*3)
(weight) @number.weight

;; 小節ジャンプ (>N)
(bar_jump) @keyword.jump

;; テンポ変化 (+5, -3)
(tempo_delta) @number.special

;; アルペジオ方向
(arp_direction) @constant.builtin

;; 和音の括弧
["[" "]"] @punctuation.bracket

;; ブロックの括弧
["{" "}"] @punctuation.bracket

;; ポート名
(port_value) @string
;; includeパス
(include_path) @string.special.path

;; コメント
(comment) @comment
(block_comment) @comment
