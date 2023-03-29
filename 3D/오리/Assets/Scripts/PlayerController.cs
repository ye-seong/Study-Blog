using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//���(Inheritance)
public class PlayerController : MonoBehaviour
{
    //Ŭ���� ��� ����(Class Member Variables): ��� ���� ������
    private Transform tr = null;
    private Rigidbody rb = null;

    //�Ӽ���(Attribute)
    [SerializeField, Range(10f, 50f)] private float moveSpeed = 10f;
    [SerializeField, Range(10f, 50f)] private float rotSpeed = 10f;

    private void Awake()
    {
        tr = GetComponent<Transform>();
        //tr = transform;
        rb = GetComponent<Rigidbody>();
    }

    /*
    <world��ǥ��>
        Vector3.up, Vector3.down, Vector3.forward, Vector3.back, Vector3.left, Vector3.right
    <Local��ǥ��>
        transform.up, transform.forward, transform.right (�ݴ������� -����)
    */

    /*
    GetKey: ����������
    */

    private void Update()
    {
        if (Input.GetKey(KeyCode.W))
        {
            //Vector3 newPos = transform.position;
            //newPos.z += moveSpeed * Time.deltaTime; //Time.dletaTime: �������ӿ��� �������ӱ��� �ɸ� �ð�
            //transform.position = newPos;
            rb.velocity = tr.forward * moveSpeed;
        }

        if (Input.GetKey(KeyCode.S))
        {
            //rb.velocity = Vector3.zero;
            Vector3 newPos = transform.position + (-tr.forward * moveSpeed * Time.deltaTime);
            transform.position = newPos;
        }

        if (Input.GetKey(KeyCode.A))
        {
            tr.Translate(Vector3.left * moveSpeed * Time.deltaTime);
        }

        if (Input.GetKey(KeyCode.D))
        {
            tr.Translate(Vector3.right * moveSpeed * Time.deltaTime);
        }

        if (Input.GetKey(KeyCode.Q))
        {
            Vector3 newRot = tr.rotation.eulerAngles;
            newRot.y -= rotSpeed * Time.deltaTime;
            tr.rotation = Quaternion.Euler(newRot);
        }

        if (Input.GetKey(KeyCode.E))
        {
            tr.Rotate(Vector3.up, rotSpeed * Time.deltaTime);
        }

        if (Input.GetKey(KeyCode.R))
        {
            tr.localScale = Vector3.one * 2f;
        }

        if (Input.GetKeyDown(KeyCode.F))
        {
            tr.localScale = Vector3.one;
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        Debug.Log("�浹�߻�");
    }
}
