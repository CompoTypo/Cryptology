
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
    return reverse(bin);
};

export function stringToBin(input: string): string {
    let output: string = "";
    let asciiRep: number;
    let asciiString: string = "";
    for (let i = 0; i < input.length; i++) {
        asciiRep = input[i].charCodeAt(0);
        output += intToBin(asciiRep) + ' ';
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
                asciiVal += (word[j].charCodeAt(0) - 48) * Math.pow(2, counter);
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
