package main

import (
	"bytes"
	"fmt"
)

type Nameval struct {
	name        string
	value       int
	left, right *Nameval
}

func (treep *Nameval) insert(newp *Nameval) *Nameval {
	if treep == nil {
		return newp
	}
	cmp := bytes.Compare([]byte(newp.name), []byte(treep.name))
	if cmp == 0 {
		return treep
	} else if cmp < 0 {
		treep.left = treep.left.insert(newp)
	} else {
		treep.right = treep.right.insert(newp)
	}
	return treep
}

func (treep *Nameval) Print() {
	if treep == nil {
		return
	}
	treep.left.Print()
	fmt.Printf("My name is %s\n", treep.name)
	treep.right.Print()
}

func main() {
	joe := &Nameval{name: "Joe"}
	bill := &Nameval{name: "Bill"}
	frank := &Nameval{name: "Frank"}
	joe.insert(bill)
	joe.insert(frank)
	joe.Print()
}
