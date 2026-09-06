(fset 'Cursor-prefix
   [nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
    nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil nil
    nil previous-line next-line forward-char backward-char nil nil nil nil
    nil nil nil nil undo nil nil execute-extended-command
    find-file save-some-buffers kill-line nil nil nil nil nil
    nil nil nil nil nil nil nil nil
    nil nil nil nil nil nil nil nil
    nil nil nil delete-char kill-word set-mark-command nil forward-line
    forward-word end-of-line other-window end-of-buffer
    beginning-of-buffer search-forward scroll-down scroll-up
    replace-string nil nil nil nil nil nil])

(global-set-key "\^[O" 'Cursor-prefix)
(global-set-key "\^[[" 'Cursor-prefix)

(defvar sun-esc-bracket t
  "*If non-nil, rebind ESC [ as prefix for Sun function keys.")
