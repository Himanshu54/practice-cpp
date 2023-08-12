## Beej's Guide

### examples
 
Testing `server.c`
```bash
$ ./a.out
---
$ nc -N 127.0.0.1 5000
---
$ sudo tcpdump -i lo
04:08:47.488063 IP localhost.34682 > localhost.5000: Flags [S], seq 3569980590, win 65495, options [mss 65495,sackOK,TS val 684988842 ecr 0,nop,wscale 7], length 0
04:08:47.488079 IP localhost.5000 > localhost.34682: Flags [S.], seq 3565514339, ack 3569980591, win 65483, options [mss 65495,sackOK,TS val 684988842 ecr 684988842,nop,wscale 7], length 0
04:08:47.488091 IP localhost.34682 > localhost.5000: Flags [.], ack 1, win 512, options [nop,nop,TS val 684988842 ecr 684988842], length 0
04:08:47.488174 IP localhost.5000 > localhost.34682: Flags [P.], seq 1:7, ack 1, win 512, options [nop,nop,TS val 684988842 ecr 684988842], length 6
04:08:47.488191 IP localhost.34682 > localhost.5000: Flags [.], ack 7, win 512, options [nop,nop,TS val 684988842 ecr 684988842], length 0
04:08:47.488206 IP localhost.5000 > localhost.34682: Flags [F.], seq 7, ack 1, win 512, options [nop,nop,TS val 684988842 ecr 684988842], length 0
04:08:47.530221 IP localhost.34682 > localhost.5000: Flags [.], ack 8, win 512, options [nop,nop,TS val 684988884 ecr 684988842], length 0

nc : World!<enter>

04:08:50.088878 IP localhost.34682 > localhost.5000: Flags [P.], seq 1:2, ack 8, win 512, options [nop,nop,TS val 684991443 ecr 684988842], length 1
04:08:50.088895 IP localhost.5000 > localhost.34682: Flags [R], seq 3565514347, win 0, length 0
---
S	SYN	Connection Start
F	FIN	Connection Finish
P	PUSH	Data push
R	RST	Connection reset
.	ACK	Acknowledgment
```

`client.c`
TBD
