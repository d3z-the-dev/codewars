import re

class Interpreter:
    env = {}

    def input(self, expression):
        if not expression or expression.isspace(): return ''
        try:
            exec('final = ' + expression)
        except:
            exec('final = ' + re.sub(r'[A-Za-z]+(?!\s*=)', 
                lambda string: str(self.env[string[0]]), expression))
        self.env.update(locals())
        return self.env['final']
