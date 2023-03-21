const findMultiples = (integer, limit) => Array.from(
	{length: ~~(limit / integer)},(x, i) => i * integer + integer)