# Useful bash code
You can use the bash code `run` for running the simulation. 
```
run() {
make
./calib run.mac
echo "simulation completed!"
root -l photoncounting.C
}
```
