Продовжую вивчати Qt Widgets замість віндового білдера..

додаю скріни - пруфи, що воно працює

інструкція для білду (shell macOS):
brew install qt cmake                  # Якщо нема
mkdir build && cd build
/opt/homebrew/bin/cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix qt)
/opt/homebrew/bin/cmake --build .
./lr10_qt_min