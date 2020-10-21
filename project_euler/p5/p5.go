package main

import "fmt"

func main() {
LOOP:
	for n := 20; ; n += 20 {
		for i := 20; i > 10; i-- {
			if n%i != 0 {
				continue LOOP
			}
		}
		fmt.Println(n)
		break
	}
}
