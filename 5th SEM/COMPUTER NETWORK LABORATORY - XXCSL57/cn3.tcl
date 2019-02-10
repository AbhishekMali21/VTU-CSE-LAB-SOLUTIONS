# Simulation parameters setup
set val(stop) 10.0 ;# time of simulation end

# Initialization
#Create a ns simulator
set ns [new Simulator]

#Open the NS trace file
set tracefile [open 5.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open 5.nam w]
$ns namtrace-all $namfile
$ns color 1 Blue
$ns color 2 Red

# Nodes Definition
#Create 9 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]

# Create LAN
$ns make-lan "$n3 $n4 $n5 $n6 $n7 $n8" 512Kb 50ms LL Queue/DropTail

# Links Definition
#Createlinks between nodes
$ns duplex-link $n1 $n0 2.0Mb 50ms DropTail
$ns queue-limit $n1 $n0 50
$ns duplex-link $n2 $n0 2.0Mb 50ms DropTail
$ns queue-limit $n2 $n0 50
$ns duplex-link $n0 $n3 1.0Mb 50ms DropTail
$ns queue-limit $n0 $n3 7
#Give node position (for NAM)
$ns duplex-link-op $n1 $n0 orient right-down
$ns duplex-link-op $n2 $n0 orient right-up
$ns duplex-link-op $n0 $n3 orient right

# Agents Definition
#Setup a TCP/Reno connection
set tcp0 [new Agent/TCP/Reno]
$ns attach-agent $n1 $tcp0
set sink1 [new Agent/TCPSink]
$ns attach-agent $n7 $sink1
$ns connect $tcp0 $sink1
$tcp0 set packetSize_ 1500
$tcp0 set class_ 1
set tfile1 [open cwnd1.tr w]
$tcp0 attach $tfile1
$tcp0 trace cwnd_

#Setup a TCP/Vegas connection
set tcp5 [new Agent/TCP/Vegas]
$ns attach-agent $n2 $tcp5
set sink6 [new Agent/TCPSink]
$ns attach-agent $n8 $sink6
$ns connect $tcp5 $sink6
$tcp5 set packetSize_ 1500
$tcp5 set class_ 2
set tfile2 [open cwnd2.tr w]
$tcp5 attach $tfile2
$tcp5 trace cwnd_

# Applications Definition
#Setup a FTP Application over TCP/Reno connection
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ns at 0.3 "$ftp0 start"
$ns at 8.0 "$ftp0 stop"

#Setup a FTP Application over TCP/Vegas connection
set ftp4 [new Application/FTP]
$ftp4 attach-agent $tcp5
$ns at 0.3 "$ftp4 start"
$ns at 8.0 "$ftp4 stop"

# Termination
#Define a 'finish' procedure
proc finish {} {
global ns tracefile namfile
$ns flush-trace
close $tracefile
close $namfile
exec nam 5.nam &
exit 0
}

$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run

