SET @salt := CONV(FLOOR( rand() * 0x100000000), 10, 16);

UPDATE `techhelpdb`.`users`
SET `password` = CONCAT(@salt, SHA(CONCAT(@salt, @typed_password)))
WHERE `ID` <> 123;

SELECT *
FROM `techhelpdb`.`users` 
WHERE SHA(CONCAT(SUBSTRING(`password`, 1, 8), @typed_password)) = SUBSTRING(`password`, 9, 40)
