# GraphBuilder build script
# Find result in dir: out/linux

[ -d out ] || mkdir out
cd out

cmake .. && cmake --build .
