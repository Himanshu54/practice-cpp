### Ordinary Pipes
- <code>pipe(int fd[])</code> create a pipe in linux
- <code>fd[0]</code> read file descriptor
- <code>fd[1]</code> write file descriptor
- only acessible to parent and child.
- scope limited to process lifetime.
- [Code](ordinary_pipe.c)

### Named Pipes
- <code>mkfifo(\<pathname>,\<pemission>)</code> create a named pipe
- Operations <code>read() , write() , open(), close()</code>
- process must be in same machine
- Code
    - [Input into pipe first](input_first.c) Write msg into pipe first then read
    - [Output from pipe first](output_first.c) Read from the spipe then write