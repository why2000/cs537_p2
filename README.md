# CS537 P2 (prodcom)

## Author:

|Name|CSlogin|NetID|
|----|-------|-----|
|Hanyuan Wu|hanyuan|hwu384|
|Zhihao Shu|hshu|zshu9|

## Install

* After git clone:
* `bash> cd cs537_p2`
* `bash> make`

## Usage

* ./prodcom
* ./prodcom < input.txt > output.txt

## Brief Summary

* A mini c-based project using self-designed queue to implement a four-thread sync IO.

## Program Features

* The Reader thread will read from standard input, one line at a time. Reader will take the each line of the input and pass it to thread Munch1 through a queue of character strings.
* Munch1 will scan the line and replace each space character (not tabs or newlines) with an asterisk ("*") character. It will then pass the line to thread Munch2 through another queue of character strings.
* Munch2 will scan the line and convert all lower case letters to upper case (e.g., convert "a" to "A"). It will then pass the line to thread Writer though yet another queue of character strings.
* Writer will write the line to standard output.

