#!/bin/bash

cp Ql3pB/config.h qmk_firmware/keyboards/zsa/moonlander/keymaps/Ql3pB
cp Ql3pB/keymap.c qmk_firmware/keyboards/zsa/moonlander/keymaps/Ql3pB
cp Ql3pB/rules.mk qmk_firmware/keyboards/zsa/moonlander/keymaps/Ql3pB
cd qmk_firmware
qmk compile -kb moonlander -km Ql3pB
