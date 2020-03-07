#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:9004,reuseaddr,fork EXEC:'setarch `uname -m` -R /pwn/pwn5',stderr" - pwnuser;
done
