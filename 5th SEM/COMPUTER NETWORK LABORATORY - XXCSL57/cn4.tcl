# Simulation parameters setup
set val(chan) Channel/WirelessChannel 	;# channel type
set val(prop) Propagation/TwoRayGround 	;# radio-propagation model
set val(netif) Phy/WirelessPhy 		;# network interface type
set val(mac) Mac/802_11 		;# MAC type
set val(ifq) Queue/DropTail/PriQueue 	;# interface queue type
set val(ll) LL 				;# link layer type
set val(ant) Antenna/OmniAntenna 	;# antenna model
set val(ifqlen) 50 			;# max packet in ifq
set val(nn) 2 				;# number of mobilenodes
set val(rp) DSDV 			;# routing protocol
set val(x) 700 				;# X dimension of topography
set val(y) 444 				;# Y dimension of topography
set val(stop) 10.0 			;# time of simulation end

# Initialization
#Create a ns simulator
set ns [new Simulator]

#Setup topography object
set topo [new Topography]
$topo load_flatgrid $val(x) $val(y)
create-god $val(nn)

#Open the NS trace file
set tracefile [open out.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open out.nam w]
$ns namtrace-all $namfile
$ns namtrace-all-wireless $namfile $val(x) $val(y)
set chan [new $val(chan)];#Create wireless channel

# Mobile node parameter setup
$ns node-config 	-adhocRouting 	$val(rp) \
			-llType 	$val(ll) \
			-macType 	$val(mac) \
			-ifqType 	$val(ifq) \
			-ifqLen 	$val(ifqlen) \
			-antType 	$val(ant) \
			-propType 	$val(prop) \
			-phyType 	$val(netif) \
			-channel 	$chan \
			-topoInstance	$topo \
			-agentTrace 	ON \
			-routerTrace 	ON \
			-macTrace 	ON \
			-movementTrace 	ON

# Nodes Definition
#Create 2 nodes
set n0 [$ns node]
$n0 set X_ 268
$n0 set Y_ 339
$n0 set Z_ 0.0
$ns initial_node_pos $n0 20
set n1 [$ns node]
$n1 set X_ 428
$n1 set Y_ 344
$n1 set Z_ 0.0
$ns initial_node_pos $n1 20

# Generate movement
$ns at .1 " $n0 setdest 600 344 100 "
$ns at .1 " $n1 setdest 300 339 100 "

# Agents Definition
#Setup a TCP connection
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink1 [new Agent/TCPSink]
$ns attach-agent $n1 $sink1
$ns connect $tcp0 $sink1
$tcp0 set packetSize_ 1500

# Applications Definition
#Setup a FTP Application over TCP connection
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ns at 1.0 "$ftp0 start"
$ns at 5.0 "$ftp0 stop"

#Define a 'finish' procedure
proc finish {} {
global ns tracefile namfile
$ns flush-trace
close $tracefile
close $namfile
exec nam out.nam &
exit 0
}

for {set i 0} {$i < $val(nn) } { incr i } {
$ns at $val(stop) "\$n$i reset"
}

$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run
