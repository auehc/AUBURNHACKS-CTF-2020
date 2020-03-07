#!/bin/bash
while : 
do
    su -c "exec socat TCP-LISTEN:9023,reuseaddr,fork EXEC:'java rev4',stderr" - revuser;
done
