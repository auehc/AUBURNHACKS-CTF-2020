#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:9024,reuseaddr,fork EXEC:'/rev/rev5 ',stderr" - revuser;
done


