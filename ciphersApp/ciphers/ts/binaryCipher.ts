
function reverse(input: string): string {
    let output: string = "";
    for (let i: number = input.length - 1; i >= 0; i--) {
        output += input[i];
    }
    return output;
};

function intToBin(asciiVal: number): string {
    let bin: string = "";
    while (asciiVal > 0) {
        bin += asciiVal;
        asciiVal /= 2;
    }
    //cout << bin << endl;
    return this.reverse(bin);
};

export function stringToBin(input: string): string {
    let output: string = "";
    let asciiRep: number;
    let asciiString: string = "";
    for (let i = 0; i < input.length; i++) {
        asciiRep = parseInt(input[i]);
        output += this.intToBin(asciiRep) + i+1 == input.length?'':' ';
    }
    return output;
}

export function binToString(input: string): string {
    let output: string = "";
    let word: string = "";
    for (let i: number = 0; i <= input.length; i++) {
        if (input[i] == ' ' || i == input.length) {
            let counter: number = 0;
            let asciiVal: number = 0;
            for (let j: number = word.length - 1; j >= 0; --j) {
                asciiVal += (parseInt(word[j]) - 48) * Math.pow(2, counter);
                ++counter;
            }
            output += String.fromCharCode(asciiVal);
            word = "";
        } else {
            word = word + input[i];
        }
    }
    return output;
}