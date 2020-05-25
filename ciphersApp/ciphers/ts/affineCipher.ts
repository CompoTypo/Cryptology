let c_A: number = 'A'.charCodeAt(0); 
let c_a: number = 'a'.charCodeAt(0);
// a and b must be coprime
let a: number = 5;
let b: number = 8;
export function encode(input: string): string {
    let output: string = '';
    for (let i: number = 0; i < input.length; i++) {
        if (input[i] != ' ') {
            let c: number = input[i].charCodeAt(0);
            if (c > 64 && c < 91) { // capital letters
                output += String.fromCharCode((((a * (c - c_A)) + b) % 26) + c_A);
            } else if (c > 96 && c < 123) { // lower case letters
                output += String.fromCharCode((((a * (c - c_a)) + b) % 26) + c_a);
            } else {
                output += input[i];
            }
        } else {
            output += input[i];
        }
    }
    return output;
}

export function decode(input: string): string {
    let output: string = '';
    let aInverse: number = 0;
    for (let i: number = 0; i < 26; i++) 
        if ((a * i) % 26 == 1) 
            aInverse = i;

    for (let i = 0; i < input.length; i++) {
        if (input[i] != ' ') {
            let c = input[i].charCodeAt(0);
            if (c > 64 && c < 91) { // capital letters
                output += String.fromCharCode(aInverse * (26 + c - c_A - b) % 26 + c_A);
            } else if (c > 96 && c < 123) { // lower case letters
                output += String.fromCharCode(aInverse * (26 + c - c_a - b) % 26 + c_a);
            }
        } else {
            output += input[i];
        }
    }
    return output;
};