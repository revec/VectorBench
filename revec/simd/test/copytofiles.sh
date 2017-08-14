F="$(ls test_*.cpp)"
files=($F)

for file in ${files[@]}; do
    cp test_canonical.in ${file}
done
