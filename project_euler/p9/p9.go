package main

import "fmt"

func main() {
	for a := 0; a <= 1000; a++ {
		b := a + 1
		c := 1000 - a - b
		aa := a * a
		for b < c {
			if aa+b*b == c*c {
				fmt.Println(a * b * c)
				return
			}
			b++
			c--
		}
	}
}
