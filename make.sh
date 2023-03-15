co()
{
    g++ $1.cpp -o $1
}
run_file()
{
    co $1
    ./$1 <input.txt >output.txt 2>error.txt
}
run()
{
    co $1
    ./$1
}
