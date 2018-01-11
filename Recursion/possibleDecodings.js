// process.stdin.resume();
// process.stdin.setEncoding("ascii");

//
// process.stdin.on("data", function (input) {
//     code += input;
// });

// process.stdin.on("end", function () {
//   permutations(code, "");
//
//   decodings = decodings.sort();
//
//   decodings.forEach(function(val){
//       console.log(val);
//   })
// });

var legend = {
    '._': 'A',
    '_...': 'B',
    '_._.': 'C',
    '_..': 'D',
    '.': 'E',
    '.._.': 'F',
    '__.': 'G',
    '....': 'H',
    '..': 'I',
    '.___': 'J',
    '_._': 'K',
    '._..': 'L',
    '__': 'M',
    '_.': 'N',
    '___': 'O',
    '.__.': 'P',
    '__._': 'Q',
    '._.': 'R',
    '...': 'S',
    '_': 'T',
    '.._': 'U',
    '..._': 'V',
    '.__': 'W',
    '_.._': 'X',
    '_.__': 'Y',
    '__..': 'Z'
}

function solve() {
  code = process.argv[2];
  permutations(code, "");
  decodings = decodings.sort();

  decodings.forEach((val)=> {
    console.log(val);
  })
}

var decodings = [];

function check(str) {
    if(legend[str]) {
        return true;
    }
    return false;
}

function permutations(code, decode) {

    if(code.length === 0) {
        decodings.push(decode);
        return;
    }

    var tempDecode = "";
    for(var i = 0; i <= 4 && code.length >= i; i++) {

        tempDecode = decode;
        if(check(code.substr(0, i))) {

            tempDecode += legend[code.substr(0, i)];
            permutations(code.substr(i, code.length), tempDecode)

        }
        tempDecode = decode;
    }
}

solve();
