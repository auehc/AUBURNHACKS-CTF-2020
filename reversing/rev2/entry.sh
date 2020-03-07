#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:9021,reuseaddr,fork EXEC:'/rev/rev2 ',stderr" - revuser;
done