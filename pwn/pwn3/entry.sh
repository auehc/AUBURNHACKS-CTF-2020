#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:9002,reuseaddr,fork EXEC:'/pwn/pwn3',stderr" - pwnuser;
done
