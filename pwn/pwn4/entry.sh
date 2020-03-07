#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:9003,reuseaddr,fork EXEC:'setarch `uname -m` -R /pwn/pwn4',stderr" - pwnuser;
done
