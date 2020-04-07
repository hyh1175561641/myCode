package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
)

func calcul(shout string) string{
	
######## 卧槽！这里不会写了
	return ("!!!!")
}


func echo(c net.Conn, shout string) {

	fmt.Println("Server Received data:", shout)


	fmt.Fprintln(c,"Client Received data:", shout,"=",calcul(shout))

}

func handleConn(c net.Conn) {
	input := bufio.NewScanner(c)
	for input.Scan() {
		echo(c, input.Text())
	}
	c.Close()
}

func main() {
	l, err := net.Listen("tcp", "localhost:8000")
	if err != nil {
		log.Fatal(err)
	}
	for {
		conn, err := l.Accept()
		if err != nil {
			log.Print(err) // e.g., connection aborted
			continue
		}
		go handleConn(conn)
	}
}
