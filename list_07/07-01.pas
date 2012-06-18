program SetExample;

type 
   rgb	   = (red, green, blue);
   sex	   = (male, remale);
   tensu   = set of 0..100;
   charset =  set of char;

var 
   x		       : integer;
   color	       : rgb;
   cset1, cset2	       : charset;
   cseta, csetb, csetc : charset;

begin
   cset1 := ['W', '1', '4', '0'];
   cset2 := ['S', 'L', '5', '0'];

   cseta := cset1 * cset2;
   csetb := cset1 + cset2;
   csetc := cset1 - cset2;

   write('整数を入力してください。：');
   readln(x);

   if(x in [1, 3, 5, 7, 9]) then
      writeln('その値は１桁の奇数です。');

end.
