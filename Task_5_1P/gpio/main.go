package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
	"time"

	"github.com/stianeikeland/go-rpio/v4"
)

var (
	pin = rpio.Pin(10) // Physical pin 19 on the RPi
)

func main() {
	setupCloseHandler()

	if err := rpio.Open(); err != nil {
		fmt.Printf("error opening the rpio connection: %v\n", err)
		os.Exit(1)
	}
	defer rpio.Close()

	pin.Output()

	for {
		pin.Toggle()
		time.Sleep(time.Second * 1)
	}
}

func setupCloseHandler() {
	c := make(chan os.Signal)
	signal.Notify(c, os.Interrupt, syscall.SIGTERM)
	go func() {
		<-c
		fmt.Println("\n- Ctrl+C pressed in Terminal")
		os.Exit(0)
	}()
}
