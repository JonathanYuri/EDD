tudo = []
for i in range(1, 6):
    ligados = int(input())
    on = []
    v_adj = []
    v_custo = []
    on.append(i)
    
    for j in range(0, ligados):
        num_adj = int(input())
        custo = int(input())
        v_adj.append(num_adj)
        v_custo.append(custo)
    
    on.append(v_adj)
    on.append(v_custo)
    tudo.append(on)
#print(tudo)

for i in range(0, 5):
    print(tudo[i])
    
#print(tudo[0][1][0])
#comecando em 1

quero_ir = -1
custo_qir = -1
for i in range(0, 3):
    print("adjacentes: ", tudo[0][1][i], end = "\t")
    print("custo: ", tudo[0][2][i])
    
    if (quero_ir == -1):
        quero_ir = tudo[0][1][i]
        custo_qir = tudo[0][2][i]
    
#procurar o adjacente
'''
for i in range(0, 5):
    if (tudo[i][0] == quero_ir):
        print("achei ", i)
'''
print(tudo[quero_ir - 1][0])
