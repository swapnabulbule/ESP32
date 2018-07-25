
broadcastPacket.c :

    This file contains only function that has to be called from example/wifi/simple_wifi.c. When wifi is connected i.e. assinged IP address then you can broadcast packets over broadcast IP address. Call this function from event handler function. This code will print when message sent and when received its response.


server.c :
        
    This code runs at other end. This program converts received packet to upper case and broadcast it. This code does not print anything on console.      
