let FromRoman (romanNumeral: string) =
    let mutable D = [|1000;500;100;50;10;5;1|]
    let mutable result = 0
    let mutable last = 0
    for c in romanNumeral do
        let index = "MDCLXVI".IndexOf(c)
        let current = D.[index]
        result <- result + current
        if current > last then
            result <- result - 2*last
        last <- current
    result

let ToRoman (n: int) =
    let mutable roman = ""
    let mutable num = n
    let d = [|"M";"CM";"D";"CD";"C";"XC";"L";"XL";"X";"IX";"V";"IV";"I"|]
    let v = [|1000;900;500;400;100;90;50;40;10;9;5;4;1|]
    for i = 0 to d.Length - 1 do
        while num >= v.[i] do
            roman <- roman + d.[i]
            num <- num - v.[i]
    roman