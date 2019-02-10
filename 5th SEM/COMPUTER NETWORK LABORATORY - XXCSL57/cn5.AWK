BEGIN {
count=0;
total=0;
}
{ 
event=$1;
if(event=="D") {
count++;
}
}
END {
printf("No of packets dropped : %d\n",count);
}