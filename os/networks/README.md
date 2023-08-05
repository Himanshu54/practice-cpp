## Beej's Guide

1. `getaddrinfo()`
```c
int getaddrinfo(const char *node,               // eg. www.example.com , 1.2.3.4
                const char *service,            // port ( http, https, ftp , 8080 etc)
                const struct addrinfo *hints,
                struct addrinfo **res);         // result ( linked-list)

```

2. `socket()`
```c
int socket(int domain, int type, int protocol); // input is *res from getaddrinfo
                                                // return socket file descriptor
```

3. `bind()`
```c
int bind(int sockfd, struct sockaddr *my_addr, int addr_len);
```
