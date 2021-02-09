import os

path = './README.md'
readme = open(path, 'w')
readme.write('# Competitive Programming 4 solutions\n')
readme.write('My solutions for [Competitive Programming 4](https://cpbook.net) book. All questions can be found [here](https://cpbook.net/methodstosolve)\n')

directory = '/Users/bryantan/Documents/Bryan/C++/CP4'
for filename in os.listdir(directory):
    if filename.startswith("Chapter"):
        readme.write('## ' + filename + "\n")
        subd = os.path.join(directory, filename)
        for subfilename in sorted(os.listdir(subd)):
            readme.write('### ' + subfilename + "\n")
            subsubd = os.path.join(subd, subfilename)
            for subsubf in sorted(os.listdir(subsubd)):
                readme.write('#### ' + subsubf + "\n")
                subsubsubd = os.path.join(subsubd, subsubf)
                for subsubsubf in sorted(os.listdir(subsubsubd)):
                    name = subsubsubf
                    name = name[:-4]
                    oj = ''
                    table_row_b = filename + '/' + subfilename + '/' + subsubf + '/' + subsubsubf
                    table_row_b = table_row_b.replace(" ", "%20")
                    table_row_a = '* ' + name + " | " + '[C++](./' + table_row_b + ')\n' 
                    readme.write(table_row_a)

    readme.write("\n")
readme.close()
