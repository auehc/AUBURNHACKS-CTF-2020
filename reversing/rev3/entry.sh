#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:9022,reuseaddr,fork EXEC:'/rev/rev3 $@',stderr" - revuser;
done
