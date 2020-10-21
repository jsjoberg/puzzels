package main

import "fmt"

func main() {
	a := 0
	b := 0
	for i := 1; i <= 100; i++ {
		a += i * i
		b += i
	}
	b *= b
	fmt.Println(b - a)

}
