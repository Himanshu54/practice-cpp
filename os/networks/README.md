## Beej's Guide

### examples
 
Testing `server.c`
```bash
$ ./a.out
---
$ nc -N 127.0.0.1 5000
---
$ sudo tcpdump -i lo -ttt -A
 00:00:00.000000 IP localhost.33902 > localhost.5000: Flags [S], seq 637764440, win 65495, options [mss 65495,sackOK,TS val 686437560 ecr 0,nop,wscale 7], length 0
E..<..@.@.y..........n..&..X.........0.........
(.4.........
 00:00:00.000012 IP localhost.5000 > localhost.33902: Flags [S.], seq 386312171, ack 637764441, win 65483, options [mss 65495,sackOK,TS val 686437560 ecr 686437560,nop,wscale 7], length 0
E..<..@.@.<............n....&..Y.....0.........
(.4.(.4.....
 00:00:00.000010 IP localhost.33902 > localhost.5000: Flags [.], ack 1, win 512, options [nop,nop,TS val 686437560 ecr 686437560], length 0
E..4..@.@.y..........n..&..Y.........(.....
(.4.(.4.
 00:00:00.000047 IP localhost.5000 > localhost.33902: Flags [P.], seq 1:7, ack 1, win 512, options [nop,nop,TS val 686437560 ecr 686437560], length 6
E..:..@.@.I3...........n....&..Y...........
(.4.(.4.World!
 00:00:00.000016 IP localhost.33902 > localhost.5000: Flags [.], ack 7, win 512, options [nop,nop,TS val 686437560 ecr 686437560], length 0
E..4..@.@.y..........n..&..Y.........(.....
(.4.(.4.
 00:00:00.000012 IP localhost.5000 > localhost.33902: Flags [F.], seq 7, ack 1, win 512, options [nop,nop,TS val 686437560 ecr 686437560], length 0
E..4..@.@.I8...........n....&..Y.....(.....
(.4.(.4.
 00:00:00.043595 IP localhost.33902 > localhost.5000: Flags [.], ack 8, win 512, options [nop,nop,TS val 686437604 ecr 686437560], length 0
E..4..@.@.y..........n..&..Y.........(.....
(.4.(.4.
 00:00:27.692082 IP localhost.33902 > localhost.5000: Flags [P.], seq 1:2, ack 8, win 512, options [nop,nop,TS val 686465296 ecr 686437560], length 1
E..5..@.@.y..........n..&..Y.........).....
(...(.4.

 00:00:00.000014 IP localhost.5000 > localhost.33902: Flags [R], seq 386312179, win 0, length 0
E..(..@.@.<............n........P...Z...
^C
---
S	SYN	Connection Start
F	FIN	Connection Finish
P	PUSH	Data push
R	RST	Connection reset
.	ACK	Acknowledgment
```

Testing with no server `client.c`
```bash
 00:00:00.000000 IP localhost.36138 > localhost.5000: Flags [S], seq 60792431, win 65495, options [mss 65495,sackOK,TS val 687705315 ecr 0,nop,wscale 7], length 0
E..<.0@.@.E..........*.....o.........0.........
(...........
 00:00:00.000010 IP localhost.5000 > localhost.36138: Flags [R.], seq 0, ack 60792432, win 0, length 0
E..(..@.@.<............*.......pP...o...
```

