;; small emacs config for offline setup

(menu-bar-mode -1)
(tool-bar-mode -1)
(scroll-bar-mode -1)
(setq inhibit-startup-screen t)
(setq ring-bell-function 'ignore)
(delete-selection-mode 1)
(save-place-mode 1)

(setq scroll-step 1)
(setq scroll-conservatively 10000)

(global-display-line-numbers-mode 1)
(setq display-line-numbers-type 'relative)

(show-paren-mode 1)
(electric-pair-mode 1)

(global-set-key (kbd "<f5>") 'compile)

(require 'ido)
(ido-mode 1)
(ido-everywhere 1)
(setq ido-enable-flex-matching t)

(global-set-key
 (kbd "M-x")
 (lambda ()
   (interactive)
   (call-interactively
    (intern
     (ido-completing-read
      "M-x "
      (all-completions "" obarray 'commandp))))))

(setq history-length 1000)
(savehist-mode 1)

(fset 'yes-or-no-p 'y-or-n-p)

(setq make-backup-files nil)
(setq auto-save-default nil)

(setq c-default-style "linux"
      c-basic-offset 4)

(setq-default indent-tabs-mode nil)
(setq-default tab-width 4)

(global-set-key (kbd "C-x C-b") 'ibuffer)

(add-to-list 'custom-theme-load-path  "emacs/")
(load-theme 'amaranth-dark t)

(when (member "DejaVu Sans Mono" (font-family-list))
  (set-face-attribute 'default nil
                      :family "DejaVu Sans Mono"
                      :height 200))
