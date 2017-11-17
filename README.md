# mutex_lock
mutex and resource managing example

#valgrind
To show the real benefits from resource-management objects one should run
```$xslt
valgrind --leak-check=full ./test/Test -r xml -d yes --order lex "Solution that leaks"
```
and
```$xslt
valgrind --leak-check=full ./test/Test -r xml -d yes --order lex "Solution that doesn't leak"
```

# submodule
If you didn't `git clone --recursive https://github.com/stefanofiorentino/mutex_lock`, then you have to 
```
git submodule update --init --recursive
```
