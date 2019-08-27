### Ordinary Pipes
- <code>pipe(int fd[])</code> create a pipe in linux
- fd[0] read 
- fd[1] write
- only acessible to parent and child.
- scope limited to process lifetime.
- [Code](ordinary_pipe.c)